inherit ROOM;
void create()
{
        set("short", "����ľ����");
        set("long", @LONG
������ϰ��Ǵ��Ϸ������ġ��ٻ��ܲ������������Ⲣ���ܺá�����������
���ں����ƺ����з���֮·����������¹⣬��������һյ��Ҳû�У��Ӱ���ʼ��
����������һƬ������������һ˫�������۾�����������������Ĵ�֡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wcloud4",
]));
        set("objects", ([
        __DIR__"npc/afa" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
