
inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
���̵Ĵ��ϰ����ǽ�ʨ�ھֵ�����ͷ�����ƹ����Ǵ���ͷ����ס�ʮ�˰�����
����������Ӧ�о��С����ܵ�ǽ�ϻ������Ű������������Ϻպ��������������Գ�
�������ű�����
LONG
        );
        set("exits", ([
		"east" : __DIR__"nwind4",
        ]));
        set("objects", ([
                __DIR__"npc/weaponer": 1,
        ]) );
        setup();
        replace_program(ROOM);

}

