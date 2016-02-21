inherit ROOM;
void create()
{
        set("short", "֪���鷿");
        set("long", @LONG
������ͥ���鳨�����й�һ������ɽˮ����һ����ͭ��¯��¯������Ʈ�졣���
��һ��������齣��ұ߼��϶�������ͼ�顣�ش�һֻ���ϣ������ķ��ı�������ͥ��
��ֲ��໨ľ�������ʮ�����ţ�����͢���ٶ������ⷢ��������������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"govern",
]));
        set("objects", ([
        __DIR__"npc/governor" : 1,
                        ]) );

        setup();
}
void init()
{
add_action("do_arrest","arrest");
add_action("do_loan" ,"loan");
add_action("do_withdraw", "withdraw");
add_action("do_balance","balance");
add_action("do_deposit", "deposit");
add_action("do_convert","convert");
}
int gethim(object target,object me)
{
        message_vision("$Nһ�仰��˵���Ҵ�ææ���뿪�ˡ�\n",target);
        target->move(this_object());
        message_vision("$N���ٱ�Ѻ�˽�����\n",target);
	if(me){
	me->kill_ob(target);
	target->kill_ob(me);
		}
        return 1;
}
int do_loan(string arg) {return 1;}
int do_withdraw(string arg) {return 1;}
int do_deposit(string arg) {return 1;}
int do_convert(string arg) {return 1;}
int do_balance(string arg) {return 1;}
int do_arrest(string arg)
{
	object me, target;
	int exp, stra,leader,factor;
	if(!arg)
	return notify_fail("��Ҫ�����˭��\n");
	me = this_player();
	if((string) me->query("class") != "official" )
	return notify_fail("�㲻�ǳ�͢��Ա�����ɼ����ɷ���\n");
	if((int) me->query("sen") < 50 )
	return notify_fail("������񲻹���\n");	
	me->add("sen",-50);
	if(!objectp(target = find_living(arg)))
	return notify_fail("�Ҳ�������Ҫ���ɷ���\n");
	if( interactive(target))
	return notify_fail("�Ҳ�������Ҫ���ɷ���\n");
	if( target->query("no_arrest") )
	return notify_fail("�Ҳ�������Ҫ���ɷ���\n");
	message_vision("$N����������������ǣ�����$n������������\n",me,target);
	exp = (int) target->query("combat_exp");
	stra = (int) me->query_skill("strategy",1);
	leader = (int) me->query_skill("leadership",1);
	factor = stra * stra * leader * leader;
	factor = (factor + ((int) me->query("combat_exp") ) - 2000 )/1000;			
	if( random(factor) <= exp)
	return notify_fail("�������ڵ��������������Լ���"+target->query("name")+"��\n");
	call_out("gethim",5,target,me);
	return 1;
}
