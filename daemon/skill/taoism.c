// taoism.c

inherit SKILL;

void create() { seteuid(getuid()); }

int valid_enable(string usage) { return usage=="literate"; }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        if( (int)me->query("bellicosity") > 100 )
                return notify_fail("���ɱ��̫�أ��޷�������ʦ������\n");
        return 1;
}

int practice_skill(object me)
{       
        return notify_fail("�����༼�ܱ�����ѧ�Ļ��Ǵ�ʵս�л�ȡ���顣\n");
}
int effective_level() { return 20;}

int learn_bonus()
{
	return -50;
}
int practice_bonus()
{
	return -25;
}
int black_white_ness()
{
	return 30;
}

