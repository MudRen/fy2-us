
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ڰ���ʪ���ڱ�����һ˿�����ս�������������һ��
ϣ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/u/taoguan/hole4",
  "south" : "/u/taoguan/hole",
]));
	setup();
        replace_program(ROOM);
}
