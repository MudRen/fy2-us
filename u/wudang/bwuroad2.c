
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
		"south" : __DIR__"xiaozhen",
		"north" : __DIR__"bwuroad1",
	]));
	set("outdoors", "wudang");
	setup();
}
void init()
{
        add_action("do_go","go");

}

int do_go()
{
if(random(2)){
this_player()->move(this_object());
return 1;
}
}
