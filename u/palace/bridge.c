
inherit ROOM;

void create()
{
        set("short", "��ľΣ��");
        set("long", @LONG
����һ����Լ�ߴ�Ķ�ľ�ţ�����������������½�ͷ����ɣ�ֻ
Ҫһ��������һʧ�㣬���̱�Ҫ������ǡ����������Լ����ʮ���ɣ�
���¿����ͱ��絶�����ƾ���ӿ������ף�Ͷ��ʯ����ȥ��Ҳ������
������
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"intersection",
  "west" : __DIR__"entrance",
]));
        set("outdoors", "palace");

        setup();
}
int valid_leave(object me, string dir)
{
	object *inv;
	object ob;
	if( userp(me))
	{
	switch(random(9)){
		case 0:
	message_vision("$N����һ�����ڶ�ľ���ϻ��˻Σ���\n",me);
	return notify_fail("���ã�û����ȥ��\n");
		break;
		case 1:
	inv = all_inventory(me);
	if(sizeof(inv)>=1)	
	{
		ob = inv[random(sizeof(inv))];
	message_vision(ob->name()+"��$N���ϻ��˳���������������Ԩ��\n",me);
		destruct(ob);
	}
	return notify_fail("���ڶ�ľ����ǰ����ϵػ��ţ�����\n");
		break;
		default:
		return 1;
		break;
			}
	}
	else
	return 1;
}

