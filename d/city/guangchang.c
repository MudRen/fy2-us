// Room: /city/guangchang.c
// YZC 1998/3/4 

inherit ROOM;

void create()
{
	set("short", "����㳡");
	set("long", @LONG
	�����ǳ��е������ģ�һ���ܿ����Ĺ㳡��������ʯ���档һЩ���ֺ���
���������������������������������ݡ�������һ�ô��������̸���ڣ���
������ǧ������䣬���������е���ʷ��֤�����ɵײ���һ���ܴ�Ķ�(shudong)��
����Կ������������Ը��ص��������������������������У�һ�ɷ������󣬶���
��ʱ�ش������ʵĶ�������������������������ˣ�һƬ�ྲ��
LONG
	);
        set("no_sleep_room",1);
        set("outdoors", "city");

	set("item_desc", ([
		"shudong" : "����һ���ڲ����еĴ󶴣����治֪����Щʲô�Ź֡�\n",
	]));

	set("exits", ([
		"east" : __DIR__"dongdajie1",
		"south" : __DIR__"nandajie1",
		"west" : __DIR__"xidajie1",
		"north" : __DIR__"beidajie1",
	]));

	set("objects", ([
		__DIR__"npc/liumang" : 2,
		__DIR__"npc/liumangtou" : 1,
		__DIR__"obj/fake-zi" : 1,
	]));

	setup();
}

void init()
{
        add_action("do_enter", "enter");
	UPDATE_D->check_user(this_player());
}

int do_enter(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="shudong" ) 
	{
		message("vision",
			me->name() + "һ�������������˽�ȥ��\n",
			environment(me), ({me}) );
                me->move("/d/gaibang/inhole");
                message("vision",
			me->name() + "�Ӷ������˽�����\n",
                	environment(me), ({me}) );
		return 1;
	}
}	
