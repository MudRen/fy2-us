inherit ROOM;
void create()
{
        set("short", "һƷ�Ӷ�¥");
        set("long", @LONG
վ�������С���Ϳ��Կ������������ķ����������ڷ���ҡҷ������������Զ
����������һƬ÷�֡�÷����¶��һ��С¥��������С��ɵ����ն���ѧ���ĵط���
÷���������·�ȼ���ǰ���ĸ�ʤ�ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" :   __DIR__"yitea",
]));
        set("objects", ([
	__DIR__"npc/lson" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
