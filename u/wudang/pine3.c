
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ï�ܵ����֣���ʱ�ܼ�����ֻ����������������ȥ����Ȼֻ�м�
˿������͸�ֶ��룬ȴ���Ե���ɭ�ɲ���ϰϰ���粻ʱӭ�洵����ʹ
�˻����泩��ʹ�����������˯��һ����
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"road2",
	]));
	setup();
	replace_program(ROOM);
}
