
inherit ROOM;

void create()
{
	set("short", "ԭʼ����");
	set("long", @LONG
������һƬ�ڰ����ڰ��г����˸�ʽ������Σ�գ�ÿһ�ֶ�����
�����������ڴ�������ʧ�˷��򣬼��ʾ�������������Ҷ��ʪ�ģ���
��Ҳ��ʪ�ġ�һ���˵�����Ҷʪ���У�ȫ������ʹ���Ť����
LONG
	);
	set("exits", ([
		"north" : __DIR__"forest6",
		"south" : __DIR__"forest2",
		"east" : __DIR__"forest3",
		"west" : __DIR__"forest1",
	]));
	set("objects", ([
		__DIR__"npc/gudumei" : 1,
	]));
	set("outdoors", "ghost");
	setup();
	replace_program(ROOM);

}
