// unarmed.c

#include <ansi.h>

inherit SKILL;

void skill_improved(object me)
{
	int s;

	s = me->query_skill("unarmed", 1);
	if( (int)me->query("str") < s/5) {
		tell_object(me, HIW "由於你勤练武艺，你的力量提高了。\n" NOR);
		me->add("str", 1);
	}
}

string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中兵刃架开。\n",
        "但是$n身子一侧，用手中兵刃格开。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 5;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

