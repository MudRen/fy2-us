// score.c

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string color);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
	mapping my;
	string line, str, skill_type, parry_type;
	object weapon;
	int attack_points, dodge_points, parry_points;

	seteuid(getuid(me));

	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	} else
		return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

	my = ob->query_entire_dbase();

//	line = sprintf( BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(ob), ob->short(1) );
        line = sprintf( "\n %s\n\n", ob->short(1) );
	line += sprintf(" ����һ%s%s%s���%s%s��%s����\n",
		ob->query("unit"),
		ob->query("national"),
		chinese_number(ob->query("age")), 
		ob->query("gender"),
		ob->query("race"),
		CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );
        line += sprintf(" �㵽ĿǰΪֹ�ܹ�ɱ�� %d ���ˣ������� %d ����������ҡ�\n",
                my["MKS"] + my["PKS"], my["PKS"]);
        if( mapp(my["family"]) ) {
                if( my["family"]["master_name"] )
                        line = sprintf("%s ���ʦ����%s��\n",
                                line, my["family"]["master_name"] );
        }
		line += sprintf(
			"\n ���ǣ�%s\t\t���ʣ�%s\n"
                        " ���ԣ�%s\t\t������%s\n"
                        " ������%s\t\t������%s\n"
                        " ������%s\t\t���ԣ�%s\n"
                        " �ٶȣ�%s\t\t������%s\n"
                        " ������%s\t\t������%s\n",
                        display_attr(my["int"], ob->query_int()),
			display_attr(my["con"], ob->query_con()),
			display_attr(my["spi"], ob->query_spi()),
			display_attr(my["per"], ob->query_per()),
			display_attr(my["cor"], ob->query_cor()),
			display_attr(my["str"], ob->query_str()),
			display_attr(my["dur"], ob->query_dur()),
			display_attr(my["fle"], ob->query_fle()),
                        display_attr(my["agi"], ob->query_agi()),
                        display_attr(my["tol"], ob->query_tol()),
                        display_attr(my["kar"], ob->query_kar()),
                        display_attr(my["cps"], ob->query_cps()));
        line += sprintf("\n ������Ʒ�� " HIR "%d\t\t" NOR, ob->query("created_item") );
        line += sprintf("���췿�䣺 " HIR "%d\n" NOR, ob->query("created_room") );
	if( objectp(weapon = ob->query_temp("weapon")) )
	{
		skill_type = weapon->query("skill_type");
		parry_type = "parry";
	}	
	else
	{
		skill_type = "unarmed";
		parry_type = "unarmed";
	}

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, parry_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

	line += sprintf(HIR"\n �������� %d" HIG "\t\t�������� %d\n" NOR,
		attack_points + 1, 
		(dodge_points/2 + (weapon? parry_points: (parry_points/2))) + 1);
	line +=sprintf(HIR" ɱ������ %d" HIG "\t\t�������� %d\n\n" NOR,
		ob->query_temp("apply/damage"),ob->query_temp("apply/armor"));

	line += sprintf(HIM" �� �� �㣺 %d\n\n" NOR, ob->query("gift_points") - 
						       ob->query("used_gift_points"));
	write(line);
	return 1;
}

string display_attr(int gift, int value)
{
	if( value > gift ) return sprintf( HIY "%3d /%3d" NOR, value,gift );
	else if( value < gift ) return sprintf( HIR "%3d /%3d" NOR, value,gift );
	else return sprintf("%3d /%3d", value,gift);
}

string status_color(int current, int max)
{
	int percent;

	if( max ) percent = current * 100 / max;
	else percent = 100;

	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : score
           score <��������>                   (��ʦר��)

���ָ�������ʾ���ָ������(������)�Ļ������ϡ�
�������ϵ��趨����� 'help figure'��


see also : hp
HELP
    );
    return 1;
}
