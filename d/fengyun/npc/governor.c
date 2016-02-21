// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({ "master yin", "master","yin" }) );
        set("long",
                "���Ƴ�����ߵĹ٣����������ϵ�Ȩ��\n");
	set("nickname", RED"һƷ�ղ�"NOR);
        set("attitude", "heroism");
	set("student_title","��Ա");
	create_family("��͢",6,"��Ա");
	set("vendetta_mark", "authority");
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
	set("agi",25);
	set("int",30);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.yuhuan" :),
        }) );
        set("combat_exp", 90000000);
	set_temp("apply/damage",500);
        set_skill("unarmed", 200);
	set_skill("sword",100);
	set_skill("force",80);
        set_skill("parry", 120);
        set_skill("dodge", 110);
	set_skill("changquan",200);
	set_skill("feixian-steps",60);
	set_skill("feixian-sword",80);
	set_skill("jingyiforce",50);
        set_skill("move", 100);
	set_skill("literate",90);
	set_skill("leadership",150);
	set_skill("strategy",150);
	map_skill("unarmed","changquan");
	map_skill("dodge","feixian-steps");
	map_skill("force","jingyiforce");
	map_skill("sword","feixian-sword");
        setup();

        carry_object(__DIR__"obj/guanfu")->wear();
}

void attempt_apprentice(object me)
{
	if( !me->query("class"))
	{
	command("smile");
	command("say �ܺã���͢��������֮ʱ��Ŭ���ɣ�\n");
        command("recruit " + me->query("id") );
	}
	else
	command("say ��͢����Ҫ�����ֲ������ģ���������֮�ˣ�\n");
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "official");
		ob->set("vendetta_mark", "authority");

}
void init()
{
        add_action("give_quest", "quest");
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","��͢��Ʒ֥���");
                return ;
        } else if ( exp <= 64000 ) {
                student->set("title","��͢��Ʒ��");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","��͢��Ʒ��");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","��͢��Ʒ��");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","��͢��Ʒ��");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","��͢��Ʒ��");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","��͢һƷ��");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","��͢�ղ��");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","��͢����ͳ��");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","��͢������ͳ��");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","��Զ����");
                return ;
        } else
                student->set("title","�����󽫾�");
                return ;

}

