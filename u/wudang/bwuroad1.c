
inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
·���������߶���һ���޼ʵ�ׯ�ڵء�˳��·����ǰ�ߣ�������
��ɽ��˳����ȥ���䵱ɽ�����ߣ�Ҳ���Ǻ���ΰ������ɽ����������
�͵Ĳ�ʱ¶��������ɫ���ݶ�������һ�������ĸо���
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"bwuroad2",
		"north" : "/u/palace/palace_path1",
	]));
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
