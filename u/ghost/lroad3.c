
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
                "north" : __DIR__"lroad2",
                "south" : __DIR__"forest",
	]));
	setup();
replace_program(ROOM);

}
