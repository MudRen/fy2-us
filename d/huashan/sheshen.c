// sheshen.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
����һ�μ�խ���յ�ɽ�£�����������ƣ�����Ԩ���޵ס��粻С��
��һʧ�����ȥ��ֻ������ͷ���Ҳ����������и�Сɽ��(dong)��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	  "eastdown" : __DIR__"canglong",
	]));
	
	set("no_die", 1);

	set("objects",([
//		__DIR__"npc/referee" : 1,
		__DIR__"npc/refereew" : 1,
//		"/u/wind/refereew2" : 1,
	]));

        set("no_clean_up", 0);
        set("outdoors", "huashan" );

        setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}



int do_enter(string arg)
{
	object me;
	mapping fam;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="dong" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "ؤ��" ) 
		{
			message("vision",
				me->name() + "����ؤ�����ǹ���һ�������������˽�ȥ��\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/underhs");
                	message("vision",
				me->name() + "�Ӷ������˽�����\n",
                		environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
	}
}	
