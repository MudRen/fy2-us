
inherit ROOM;

void create()
{
	set("short", "����ɽׯ");
	set("long", @LONG
����һ�����˵����硣����������һƬ���ɣ�ʲô������������
����һ��Ұ�ɫ��Сľ�ݣ����������İ����һ��Ҫ��ע��ſ�
�õ���
LONG
	);
	set("exits", ([
                "north" : __DIR__"house",
                "west" : __DIR__"bridge",
                "east" : __DIR__"groad1",
	]));
	setup();
        replace_program(ROOM);
}
