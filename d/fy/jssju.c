
inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
�˼�����Ƿ��Ƴ���������࣬���ĵط���������ϰ������������˵�ǵ����
̫�ӵ���ʦ�����Ǿ����������飬���������͵����Ȼ��̰�ӡˢ�����ﲻ���ܶ��
ɧ����ϲ����ʫ�ʣ�����һЩ��ǳ�Ĺ����飬�����о�������ǿ���塣
LONG
        );
        set("exits", ([
		"east" : __DIR__"nwind1",
        ]));
        set("objects", ([
                __DIR__"npc/bookseller": 1,
        ]) );
        setup();
        replace_program(ROOM);

}
