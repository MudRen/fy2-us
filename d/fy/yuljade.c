inherit ROOM;
void create()
{
        set("short", "�����鱦��");
        set("long", @LONG
�鱦��������ǿ�ǧ������ɵ�����������������֣�����������֮�С�������
������������ȭͷ��С���������Ρ����۰�����ա����ܵ�ǽ�Ϲ����˸��ֽ�����
Ʒ�͸��ֻ�����������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"swind1",
]));
        set("objects", ([
        __DIR__"npc/jadeowner" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
