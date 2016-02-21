// learn.c

#include <skill.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
        "˵������̫�����ˣ�������ҵ���\n",
        "�����ܳ�����һ����˵������̣�������ҵ���\n",
        "Ц��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲ�᣿\n",
});
int couple_learn(object me, object couple, string skill);
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string skill, teacher, master;
        object ob, *list, marry_card;
        int master_skill, my_skill, gin_cost;
        string target, cardname;
        int i,marry_flag;
	int amount=0, pot;

        if(!arg || sscanf(arg, "%s from %s with %d", skill, teacher, pot)!=3 )
                return notify_fail("ָ���ʽ��learn <����> from <ĳ��> with <Ǳ�ܵ�>\n");

        if( me->is_fighting() )
                return notify_fail("����ĥǹ������������\n");

        if( !(ob = present(teacher, environment(me))) || !ob->is_character())
                return notify_fail("��Ҫ��˭��̣�\n");

        if( !living(ob) )
                return notify_fail("��....����Ȱ�" + ob->name() +
"Ū����˵��\n");
	if ( pot <=0 )
		return notify_fail("Ǳ�ܵ�������һ��\n");
	target = (string)me->query("marry");

        if( !me->is_apprentice_of(ob) ) {
                if (ob->query("id") != target) {
                if( (string)me->query("family/family_name") !=
(string)ob->query("family/family_name")
                ||      (int)ob->query("family/privs") != -1 ) {
                        notify_fail( ob ->name() +
reject_msg[random(sizeof(reject_msg))] );
                        if( !(ob->recognize_apprentice(me)) ) return 0;
                }
                }
        }
        // the query_skill is need to prevent a bug in
        //query-skill-eff_lvlv :(( tie
                if( !master_skill = ob->query_skill(skill,1) )
                                return notify_fail("���������±����ұ���ѧ�ˡ�\n");
                                                                                
        if( !master_skill = ob->query_skill_eff_lvl(skill) )
                return notify_fail("���������±����ұ���ѧ�ˡ�\n");

        notify_fail(ob->name() + "��Ը���������ܡ�\n");
        if( ob->prevent_learn(me, skill) )
                return 0;
	if( target == ob->query("id"))
		if( couple_learn(me,ob,skill))
			return 0;
        my_skill = me->query_skill_eff_lvl(skill);
        if( my_skill >= master_skill )
                return notify_fail("�������ĳ̶��Ѿ�������ʦ���ˡ�\n");

        notify_fail("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");
        if( !SKILL_D(skill)->valid_learn(me) ) return 0;

        gin_cost = 100 / (int)ob->query_int();

//	casue problem under query-skill-eff-lvl
        if( (int)me->query_skill(skill,1) == 0 ) {
                gin_cost *= 2;
                me->set_skill(skill,0);
        }
	gin_cost *= pot;
        if( (int)me->query("potential") - 
	(int)me->query("learned_points") < pot )
                return
notify_fail("���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");
        printf("����%s����йء�%s�������ʡ�\n", ob->name(),
                to_chinese(skill));

        if( ob->query("env/no_teach") )
                return notify_fail("����" + ob->name() +
"���ڲ���׼���ش�������⡣\n");

        tell_object(ob, sprintf("%s��������йء�%s�������⡣\n",
                me->name(), to_chinese(skill)));

        if( (int)ob->query("sen") > gin_cost/5 + 1 ) {
                if( userp(ob) ) ob->receive_damage("sen", gin_cost/5 + 1);
        } else {
                write("����" + ob->name() +
"��Ȼ̫���ˣ�û�а취����ʲ�ᡣ\n");
                tell_object(ob, "������̫���ˣ�û�а취��" + me->name() +
"��\n");
                return 1;
        }
        if( (int)me->query("gin") > gin_cost ) {
                      if((my_skill * my_skill * my_skill)/10  >
	(int)me->query("combat_exp") ) {
	printf("Ҳ������Ϊȱ�����飬���%s�Ļش������޷���ᡣ\n", ob->name() );
                } else {
                        printf("������%s��ָ�����ƺ���Щ�ĵá�\n",
ob->name());
                        me->add("learned_points", pot);
	amount = (my_skill - 75) * SKILL_D(skill)->black_white_ness()/100;
	if((amount < -50) && (my_skill < 75)) amount = -50;
// however, we won't make learn so easy
//      amount  += random((int)me->query_int()+((float)me->query("combat_exp")/1000)
//              + SKILL_D(skill)->learn_bonus() ;
	amount += SKILL_D(skill)->learn_bonus() +
		  (int)me->query_int() * (int)me->query_int() +
		  to_int(pow(to_float((int)me->query("combat_exp")),0.3));
//        write(sprintf("%d\n",amount));
	amount = amount/50 + random(amount/50);
	if( amount < 2) amount = 2;	
//        write(sprintf("%d\n",amount));
	amount *= pot;
                        me->improve_skill(skill,amount);
                }
        } else {
                gin_cost = me->query("gin");
                write("�����̫���ˣ����ʲ��Ҳû��ѧ����\n");
        }

        me->receive_damage("gin", gin_cost );

        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : learn <����> from <ĳ��> with <Ǳ�ܵ�>

���ָ������������������й�ĳһ�ּ��ܵ��������⣬��Ȼ������̵Ķ�������
����ϵ�����������ߣ����㾭�����ַ�ʽѧϰ�����ļ���Ҳ�����ܸ��������
�̵��ˣ�Ȼ����Ϊ����ѧϰ��ʽ�൱�һ�֡�����Ĵ��С������ѧϰ����˵����Ϥ
һ���¼������ķ�����

ͨ����һ���˸�ѧ��һ���¼����ǲ�����ʲ����������ģ����Ǿ���ʵ���ϵ�Ӧ����
�������⣬��Щ������ѧϰһ���¼��ܵĹ����Ǻ���Ҫ�ģ������Ǹ�����Ϊ������
�ܻ����Ļ������ܣ�����Ҫ���ɡ��������⡪������⡹�Ĺ��̲��ܵõ��Ϻõ�Ч��
������ǽ����ַ�������Ĺ����á�Ǳ�ܡ��Ĺ����ʾ��һ�����ܹ��Լ�����ĳЩ��
�⣬��ʾ��(��)�н�����������Ǳ�ܣ��������������Ǳ��ʱ�Ϳ����������ָ��
������������̣�����ý�����
(PS. Ǳ�ܻ�������������Ķ��壬����ֻ������֮һ )

����ѧϰҲ��Ҫ����һЩ�����������ĵľ��������Լ�������ѧϰ����������йء�

������֪�����ܴӶԷ�ѧ��ʲ�Ἴ�ܣ�����Է������ʦ���������� skills ָ��
ֱ�Ӳ鿴������������ʦ��������ͨ��������������ʾ����ֻ���Լ���취��

�������ָ�� : practice��study
HELP
        );
        return 1;
}

int couple_learn(object me, object couple, string skill)
{
	int i, div,mylvl, herlvl, ratio=1;
	if(!userp(couple)) return 0;
	mylvl = me->query_skill(skill,1);
	herlvl = couple->query_skill(skill,1);
	div = (int) me->query("divorced");
	for(  i=1; i<=div; i++) ratio *= 2;
	if( (mylvl >= herlvl / ratio) && ratio != 1)
	{
	message_vision("$N��ɫ���ƺ���$n����ʮ�����Σ�Ҳ��������$p��ǰ��������...��\n", couple, me );	
	return 1;	
	}
	return 0;
}
