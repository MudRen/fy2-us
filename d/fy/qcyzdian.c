
inherit ROOM;

void create()
{
        set("short", "�����֬��");
        set("long", @LONG
��������Ÿ�ʽ��������֬���дӾ��������ģ�Ҳ�б��ز��ġ���֬�ʺ���Ѫ,
�����˱ǡ�ÿ����������������������ڣ�ӳ����֬�ϣ�����һ��ҫ�۵����졣��
����֬���������ٻ��ͣ����۴������ϰ���˵���ǵ��꽭�������������ݸ��֡�
LONG
        );
        set("exits", ([
		"east" : __DIR__"nwind2",
        ]));
        set("objects", ([
                "/d/fengyun/npc/makeupseller": 1,
		__DIR__"npc/younggirl": 2,
        ]) );
        setup();
        replace_program(ROOM);

}
