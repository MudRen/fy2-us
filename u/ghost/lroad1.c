
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
                "north" : "/u/guanwai/citygate",
                "south" : __DIR__"lroad2",
	]));
	setup();
replace_program(ROOM);

}
