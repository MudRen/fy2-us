inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��ʯ");
        set("long", @LONG
����һ��޴�İ�ɫɽʯ����Լ�����������߸��ˡ�ʯͷ�ı����쳣
ƽ�������˾������ʯ���ϵļ����ɫӡ�ۣ���֪����Ȼ���ɣ�������Ϊ
�ĺۼ��������������Կ��������ĺ�ˮ����������ֻ�������������ƣ���
֪���ж�߲Żᵽ����
LONG
        );
	set("outdoors","fengyun");
        setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_step", "step");
}

int do_step(string arg)
{
	if(!arg || arg != "��ɫӡ��" )
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision(HIY "$Nһ�Ų���ʯ���ϵĺ�ɫӡ�ۣ�ֻ������֨ѽ��һ����\n�±����ѿ���һ���Ż���\n" NOR, this_player());
	set("exits/enter", __DIR__"holeopen2");
	return 1;
}

int do_climb(string arg)
{
        object 	me;
	int	mlvl;

	if(!arg || (arg != "up" && arg != "down")) {
		write("��Ҫ���ϻ�������\n");
		return 1;
	}
	me = this_player();
	if( arg == "up") {
		message_vision(HIY "\n$NС�������������ȥ�������������������ڡ�\n" NOR, me);
		message_vision(HIR "\n$N����һ��ûץ�ȣ���Σ���ϵ�����ȥ��\n" NOR, me);
		me->move(__DIR__"yadi");
                me->receive_wound("kee", 50);
                me->receive_wound("sen", 50);
                me->receive_wound("gin", 50);
		message_vision(HIR "\n$N��Σ���ϵ������������ص�ˤ���˵��ϣ�\n" NOR, me);
		me->unconcious();
	}
	else {
		message_vision(HIY "$NС�������������ȥ�������������������ڡ�" NOR, me);
		me->move(__DIR__"yadi");
	}
	return 1;
}
