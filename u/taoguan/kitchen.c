#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���幬����");
	set("long", @LONG
һ�䲻��ĳ�����ȴ�Ǹɸɾ��������濿ǽ��һ���ܴ�
��¯�����ǽ�ǰ��ż�̳�þơ��м��һ�Ŵ����ϰ��ŵ�
���ˣ�ɢ��������������������ʿ����æ��������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"west" : "/u/taoguan/da_yuan",
]));
        set("objects", ([ /* sizeof() == 2 */
                "/u/taoguan/npc/reg_taoist" : 2,
]));
	setup();
	replace_program(ROOM);
}
