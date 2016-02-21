// Room: /city/duchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�ĳ�");
	set("long", @LONG
�����Ƕĳ��Ĵ��ã����ܵķ����ﴫ����ߺ������ĶĲ�����
�����Ƕġ���С���ķ��䣬�����Ƕġ��ƾš��ķ���(not yet available)��
ǽ�Ϲ���һ������(paizi)��
LONG
	);

	set("item_desc", ([
		"paizi" : "��¥�Ĺ��������ڲ��Խ׶Ρ�\n",
	]));
	set("exits", ([
                //"west" : "/u/ding/daxiao",
		"up" : __DIR__"duchang2",
		"east" : __DIR__"nandajie1",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "west" && this_player()->query("age")<18)
                return notify_fail("Сë���������Ϲ�պ�ʲô?!\n");
        return ::valid_leave(me, dir);
}

