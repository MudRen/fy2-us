
inherit ROOM;

void create()
{
	set("short", "��ջ");
	set("long", @LONG
��ջ��ǰ��һ�����ɸߵ���ˣ���������ĸ�����ĵ���������
д������ƽ��ջ���˿�ջ���䵱�׼ҵ��ӣ��˳ơ���ƽ���͡�������
��������ջ���Ǻܴ󣬵�װ�εú����š���ʹ�����䵱ɽ���Ƶ��ˣ�
������Ҳ�����ܵ��ܺõ��д���
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"xzroad1",
	]));
        set("objects", ([
                __DIR__"npc/waiter" : 1,
        ]) );
	setup();
replace_program(ROOM);

}
