// wdroad3.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
	һ���ӿ����ݵ���·������������ͨ��ɽ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southeast" : __DIR__"hsroad2",
		"north" : __DIR__"sexit",
	]));

	setup();
	replace_program(ROOM);
}

