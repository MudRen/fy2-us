// wdroad2.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
	������һ����ʯ����ϣ��ϱ���Լ�ɼ������ݳǵĳ�ǽ��
	����һ����·ͨ��ɽ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"south" : __DIR__"hsroad1",
		"north" : "/d/shaolin/yidao",
		"northwest" : __DIR__"hsroad3",
	]));

	setup();
	replace_program(ROOM);
}

