
inherit ROOM;

void create()
{
	set("short", "ʯӢ��ʯ��");
	set("long", @LONG
��������һ��������ʯӢ�ҽ�����, ���ݵ�������ֲ��һ�Ÿ���
��������̧ͷ������������������ͦ�ε�ɽ��, ������Ʈ���ɽ����
������һ����ΰ�İ�ɫ¥��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : "/u/taoguan/road4",
  "southdown" : "/u/taoguan/road2",
]));
	set("outdoors", "taoguan");
	setup();
	replace_program(ROOM);
}
