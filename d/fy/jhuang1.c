inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���¾���ר�Ÿ����Ǯ���ܶ�İ�ȫ���������ˣ���Ҫ�������ǵļ�졣��������
���ְ���Ϣ�����ڡ������м���С��������С����ÿ�Ŵ�ͷ����С���������Ƕ��ѱ�
�����ڹ��ϣ�һ���֣����ǾͿ��������ٶȰγ��Լ��ı��С�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jting",
  "south" : __DIR__"jbang",
]));
        set("objects", ([
        __DIR__"npc/huangyi" : 3,
                        ]) );

        setup();
        replace_program(ROOM);
}
