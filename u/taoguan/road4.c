
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ����ʯ���̳ɵ�ɽ����������ï�ܵ���ľ����ǰ�����
������·�Ѿ��������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : "/u/taoguan/road5",
  "southdown" : "/u/taoguan/road3",
]));
	set("outdoors", "taoguan");
	setup();
	replace_program(ROOM);
}
