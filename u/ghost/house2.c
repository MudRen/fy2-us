
inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
���Ӳ��󣬵����õú����¡����濿ǽ����һ�Ŵ󴲣�����ѩ��
����ո�¡����洲ͷ��һ����ױ̨��̨�Ϸ���һ��ͭ����������֬��
LONG
	);
	set("exits", ([
                "north" : __DIR__"groad5",
	]));
	set("objects", ([
                __DIR__"npc/hua" : 1,
	]));
	setup();
replace_program(ROOM);

}
