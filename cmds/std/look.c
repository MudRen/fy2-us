// look.c

#include <room.h>
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string getper(object me, object obj);
string tough_level(int power);
string gettof(object me, object obj);
string getdam(object me, object obj);
string *tough_level_desc = ({
        BLU "����һ��" NOR,
        BLU "��������" NOR,
        BLU "����ҳ�" NOR,
        BLU "��ѧէ��" NOR,
        HIB "�����ž�" NOR,
        HIB "��֪һ��" NOR,
	HIB "����ͨͨ" NOR,
	HIB "ƽƽ����" NOR,
        HIB "ƽ������" NOR,
        HIB "��ͨƤë" NOR,
        HIB "��������" NOR,
        HIB "������" NOR,
	HIB "����С��" NOR,
        HIB "����С��" NOR,
        HIB "�������" NOR,
        CYN "�������" NOR,
        CYN "��Ȼ���" NOR,
	CYN "���д��" NOR,
	CYN "���д��" NOR,
        CYN "��Ȼ��ͨ" NOR,
        CYN "�������" NOR,
	CYN "�޿�ƥ��" NOR,
	CYN "����Ⱥ��" NOR,
        CYN "����似" NOR,
        CYN "�����뻯" NOR,
	CYN "����Ⱥ��" NOR,
        HIC "�Ƿ��켫" NOR,
	HIC "��������" NOR,
        HIC "һ����ʦ" NOR,
	HIC "�񹦸���" NOR,
        HIC "������˫" NOR,
        HIC "��������" NOR,
        HIC "������" NOR,
	HIC "��ز�¶" NOR,
        HIR "��ɲ�" NOR
});
string *heavy_level_desc= ({
	"����",
	"����",
	"����",
	"����",
	"����",
	"����"	
});
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj;
	int result;

	if( !arg ) result = look_room(me, environment(me));
	else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
		if( obj->is_character() ) result = look_living(me, obj);
		else result = look_item(me, obj);
	} else result = look_room_item(me, arg);

	return result;
}

int look_room(object me, object env)
{
	int i;
	object *inv;
	mapping exits;
	string str, *dirs;

	if( !env ) {
		write("������ܻ����ɵ�һƬ��ʲ��Ҳû�С�\n");
		return 1;
	}
	str = sprintf( "%s - %s\n    %s%s",
		env->query("short"),
		wizardp(me)? file_name(env): "",
		env->query("long"),
		env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	if( mapp(exits = env->query("exits")) ) {
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				dirs[i] = 0;
		dirs -= ({ 0 });
		if( sizeof(dirs)==0 )
			str += "    ����û���κ����Եĳ�·��\n";
		else if( sizeof(dirs)==1 )
			str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
		else
			str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + " �� " + BOLD + "%s" + NOR + "��\n",
				implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
	}
//	str += env->door_description();

	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]==me ) continue;
		if( inv[i]->query("no_shown")) continue;
		if( !me->visible(inv[i]) ) continue;
		str += "  " + inv[i]->short() + "\n";
	}

	write(str);
	return 1;
}

int look_item(object me, object obj)
{
	mixed *inv;
	string prep;

	write(obj->long());
	inv = all_inventory(obj);
	if( !obj->is_closed() && sizeof(inv)) {
		switch( (string)obj->query("prep") ) {
			case "on":
				prep = "��";
				break;
			case "under":
				prep = "��";
				break;
			case "behind":
				prep = "��";
				break;
			case "inside":
				prep = "��";
				break;
			default:
				prep = "��";
				break;
                        }
		inv = map_array(inv, "inventory_look", this_object() );
		message("vision", sprintf("%s���У�\n  %s\n", prep,
			implode(inv, "\n  ") ), me);
	}
	return 1;
}

string getper(object me, object obj)
{
	int per;
	int spi;

	int weight;
	string str;

	per = obj->query_per();
	spi = me->query_spi();

// ���Բ���˿��Ĳ�׼
	if (spi>35) weight = 0;
	else weight = (int)(35 - spi)/4 ;


	if (random(10)>6) per = per - weight;
	else per = per + weight ;

	
	if ((string) obj->query("gender") == "����") {
		if (per > 20) str = "����ò����,������һ��\n";
		if ((per >= 15) && (per <=30)) 
			str = "��Ӣ������,ò���˰���\n";
		if ((per >= 10) && (per < 25)) 
			str = "����ٶ�����\n";
		if (per < 5) 
			str = "����òƽƽ��\n";
	}
	else if  ((string) obj->query("gender") == "Ů��"){
		if (per > 25)
			str = "����ۼ����,�����˼����ӣ�\n";
		if ((per >= 20) && (per <= 30)) 
			str = "���г�������֮��,�����߻�֮ò��\n";
		if ((per >= 15) && (per < 25)) 
			str = "����������,�������ˣ�\n"; 
		if ((per >= 10) && (per < 20))
			str = "����òƽƽ,�����ù�ȥ��\n";
		if (per < 5) 
			str = "������ò��...�������ɡ�\n";
	}
	if (!(string) obj->query("family")) 
	{
	if(str) str +="��������������㲢�������ơ�\n";
	else str = "��������������㲢�������ơ�\n";
	}
	if( !str) str="";
	return str;
}
string gettof(object me, object ob)
{
	object weapon;
	string skill_type,parry_type;
	int attack_points;
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
	return  tough_level(attack_points);
}
int look_living(object me, object obj)
{
	string str, limb_status, pro;
	mixed *inv;
	mapping my_fam, fam;

	if( me!=obj )
		message("vision", me->name() + "�������㿴����֪����Щʲ�����⡣\n", obj);

	str = obj->long();

	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

	if( (string)obj->query("race")=="����"
	&&	intp(obj->query("age")) )
		str += sprintf("%s������Լ%s���ꡣ\n", pro, chinese_number(obj->query("age") / 10 * 10));
		str+=getper(me,obj);
		str +=sprintf("�书����������");
		str+=gettof(me,obj);
		str += sprintf("��");
		str +=sprintf("�����ƺ�");
		str +=getdam(me,obj);
                str += sprintf("��\n");
	// If we both has family, check if we have any relations.
	if( obj!=me
	&&	mapp(fam = obj->query("family"))
	&&	mapp(my_fam = me->query("family")) 
	&&	fam["family_name"] == my_fam["family_name"] ) {
	
		if( fam["generation"]==my_fam["generation"] ) {
			if( (string)obj->query("gender") == "����" )
				str += sprintf( pro + "�����%s%s��\n",
					my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
					my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
			else
				str += sprintf( pro + "�����%s%s��\n",
					my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
					my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
		} else if( fam["generation"] < my_fam["generation"] ) {
			if( my_fam["master_id"] == obj->query("id") )
				str += pro + "�����ʦ����\n";
			else if( my_fam["generation"] - fam["generation"] > 1 )
				str += pro + "�����ͬ�ų�����\n";
			else if( fam["enter_time"] < my_fam["enter_time"] )
				str += pro + "�����ʦ����\n";
			else
				str += pro + "�����ʦ�塣\n";
		} else {
			if( fam["generation"] - my_fam["generation"] > 1 )
				str += pro + "�����ͬ������\n";
			else if( fam["master_id"] == me->query("id") )
				str += pro + "����ĵ��ӡ�\n";
			else
				str += pro + "�����ʦֶ��\n";
		}
	}

	if( obj->query("max_kee") )
		str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100 / (int)obj->query("max_kee")) + "\n";

	inv = all_inventory(obj);
	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
		inv -= ({ 0 });
		if( sizeof(inv) )
			str += sprintf( obj->is_corpse() ? "%s�������У�\n%s\n" : "%s���ϴ�����\n%s\n",
				pro, implode(inv, "\n") );
	}

	message("vision", str, me);

	if( obj!=me 
	&&	living(obj)
	&&	random((int)obj->query("bellicosity")/10) > (int)me->query_per() ) {
		write( obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
		COMBAT_D->auto_fight(obj, me, "berserk");
	}

	return 1;
}

string inventory_look(object obj, int flag)
{
	string str;

	str = obj->short();
	if( obj->query("equipped") )
		str = HIC "  ��" NOR + str;
	else if( !flag )
		str = "    " + str;
	else
		return 0;

	return str;
}

int look_room_item(object me, string arg)
{
	object env;
	mapping item, exits;

	if( !objectp(env = environment(me)) )
		return notify_fail("����ֻ�л����ɵ�һƬ��ʲ��Ҳû�С�\n");

	if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
		if( stringp(item[arg]) )
			write(item[arg]);
		else if( functionp(item[arg]) )
			write((string)(*item[arg])(me));
			
		return 1;
	}
	if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
		if( objectp(env = find_object(exits[arg])) )
			look_room(me, env);
		else {
			call_other(exits[arg], "???");
			look_room(me, find_object(exits[arg]));
		}
		return 1;
	}
	return notify_fail("��Ҫ��ʲ�᣿\n");
}
string tough_level(int power)
{

	int lvl;
	int rawlvl;
	int grade = 1;
	if(power<0) power=0;
	rawlvl = (int) pow( (float) 1.0 * power, 0.3);
	lvl = to_int(rawlvl/grade);
                        if( lvl >= sizeof(tough_level_desc) )
                                lvl = sizeof(tough_level_desc)-1;
                        return tough_level_desc[((int)lvl)];
}
string getdam(object me, object obj)
{

	int level;
	level = obj->query_temp("apply/damage");
	level = level / 50;
                        if( level >= sizeof(heavy_level_desc) )
                                level = sizeof(heavy_level_desc)-1;
                        return heavy_level_desc[((int)level)];
}

int help (object me)
{
	write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]
 
���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���
 
HELP
);
	return 1;
}
