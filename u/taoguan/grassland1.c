
inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
���ϳ��Ÿ�ʽ�����Ļ��ݣ������������ﶼ���Ѽ�������
��ҩ�ݣ����������û��Ҫһ�������������Ƕ��͵�ɽ�£���
����һ�������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : "/u/taoguan/lake1",
  "north" : "/u/taoguan/grassland2",
  "south" : "/u/taoguan/hole4",
]));
	set("outdoors", "taoguan");
	setup();
        replace_program(ROOM);
}
