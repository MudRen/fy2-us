inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����������ﲻʤ�ߡ�
����ϴ�������ۣ�����ҡŪ����֫����������ˡ�
���������������ŵ͡�
�߷����˴����������ѩů��ʱ�������������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"yue",
  "west" : __DIR__"xue",
]));
        set("objects", ([
        __DIR__"npc/liu" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
