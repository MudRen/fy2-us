
inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����ͨͨ��һ���ӻ��ꡣ��ǽ�ļ����ϰ����������������Ʒ��
�м�һ�Ź�̨�������������ڹ�̨�������ʡ�����ʱ��̧ͷ��һ����
�⣬�����ڵȴ�ʲô�ˡ�
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"xzroad3",
	]));
        set("objects", ([
                __DIR__"npc/seller2" : 1,
                __DIR__"npc/taoist2" : 1,
        ]) );
	setup();
replace_program(ROOM);

}
