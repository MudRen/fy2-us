
inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ������������·��·���Ӳݴ�����·����Ţ����������ǰ��
�ͽ�����һƬԭʼɭ�֣���û���߳������
LONG
	);
	set("exits", ([
                "north" : __DIR__"lroad1",
                "south" : __DIR__"lroad3",
	]));
	setup();
replace_program(ROOM);

}
