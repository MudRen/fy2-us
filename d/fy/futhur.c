inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����������Ψһ�Ƚ������Ľ���������ɫ�ܹ֣�һ��Ѫɫ�����İ���ɫ���������
����ɭɭ�������޴���һյ�͵ƺ�����������̫������ͼΪ�׵���������׭�������
���֡������Ѳ�����Ҳ�������޹�ĺ�ɫ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wcloud3",
]));
        set("objects", ([
        __DIR__"npc/dashi" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
