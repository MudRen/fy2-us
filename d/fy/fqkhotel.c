inherit ROOM;
void create()
{
        set("short", "����˿�ջ");
        set("long", @LONG
ǰ������һ������˫�ɵľ޻������Ź��Ŷ�ԧ��������ϵ�ż���СС�Ļ�ͭ���塣
΢���ӹ������巢������ö��Ķ�����������������Ŷ���Ĵ��������ϸ�������
�֡������Ϻ���һ�������֡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"swind1",
]));
        set("objects", ([
        __DIR__"npc/waiter" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
