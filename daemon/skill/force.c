// force.c

#include <ansi.h>

inherit SKILL;

int valid_learn(object me) { return 1; }

string exert_function_file(string func)
{
        return "/d/force/" + func;
}

void skill_improved(object me)
{
        int s;

        s = me->query_skill("force", 1);
        if((int)me->query("con") < s/5) {
                tell_object(me, HIW 
"�������ڹ������гɣ�������ʸ����ˡ�\n" NOR);
                me->add("con", 1);
        }
}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

