
inherit ROOM;

void create()
{
	set("short", "СԺ");
	set("long", @LONG
Ժ���������������ݣ�������Ļ�ľ������ҩ�ݣ���ʽ������
�����ۻ����ҡ���ʯС·���ɻ����д�����Ժ��������һ���˽�ͤ��
��ɫ��ͤ������ɫ��ͤ����ͤ������һ��ʯ������ֻʯ�ʡ�
LONG
	);
	set("exits", ([ 
  		"east" : __DIR__"wuroad4",
  		"west" : __DIR__"wuroad2",
	]));
	set("outdoors", "wudang");
	setup();
	replace_program(ROOM);
}
