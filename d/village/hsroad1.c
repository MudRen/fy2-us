// wdroad1.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
	������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С��ϱ�ͨ�����ݳǡ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"north" : __DIR__"hsroad2",
		"south" : "/d/city/beimen",
	]));

	setup();
	replace_program(ROOM);
}

