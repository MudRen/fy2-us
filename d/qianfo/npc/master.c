// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("�˹���ʦ", ({ "master xing", "master", "xing" }) );

        set("gender", "����");
        set("age", 74);
        set("attitude", "peaceful");
        set("class", "bonze");
        set("apprentice_available", 3);
	set("student_title","��ʦ");
        set("str", 27);
        set("int", 30);
        set("spi", 30);
        set("con", 30);
        set("spi", 30);
        set("con", 30);
        set("cps", 30);
        set("cor", 20);
        set("agi",25);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.longxianyuye" :),
        }) );
        set("atman", 300);
        set("max_atman", 300);
        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 5);
        set("mana", 300);
        set("max_mana", 300);
        set("combat_exp", 1000000);
        set("score", 9000);
        set_skill("staff", 100);
	set_skill("changquan",100);
        set_skill("unarmed", 120);
        set_skill("force", 100);
        set_skill("dodge", 120);
        set_skill("literate", 80);
        set_skill("chanting", 100);
        set_skill("parry", 120);
        set_skill("magic", 100);
        set_skill("cloudstaff", 100);
        set_skill("lotusforce", 100);
        set_skill("buddhism", 100);
        set_skill("essencemagic", 100);
        set_skill("notracesnow",120);
        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");
        map_skill("force", "lotusforce");
        map_skill("magic", "essencemagic");
        map_skill("dodge","notracesnow");
	map_skill("unarmed", "changquan");
        create_family("�˹�����", 3, "ס��");
        setup();
        carry_object(__DIR__"obj/buddha_staff")->wield();
	carry_object("/obj/cloth")->wear();

}

void init()
{
        add_action("give_quest", "quest");
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say ���ɽ����Ѿ��չ��˵��ӣ���������ͽ�ˡ�");
        }
}

void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "����" )
                command("say �����ӷ�Ůʩ����Ҫ�����ɿ���Ц��");
        else if(ob->query_temp("marks/ye")){
		ob->set("class","bonze");
		command("say ���ڰ��Ƴ����ķ��ϣ��Ҿ�����Ϊͽ�ɣ�\n");
                command("say �����ӷ����գ����գ�");
                command("recruit " + ob->query("id") );
        }
	else if(ob->query_temp("marks/lady")){
                ob->set("class","bonze");
                command("say �����㲻��������������Ϊ�ķ��ϣ��Ҿ�����Ϊͽ�ɣ�\n");
                command("say �����ӷ����գ����գ�");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                add("apprentice_availavble", -1);
                return 1;
        }
}

int accept_fight(object me)
{
        if( (string)me->query("class")=="bonze" )
                command("say �����ӷ𣡳����˽��ǿ�񶷣����Ĳ���Υ����档");
        else
                command("say ʩ����Ȼ�����գ�����������ǣ�Ҳ���ؽ����ˡ�");

        return 0;
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","�˹����´�ʦ");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","�˹������޺�");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","�˹����½��");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","�˹����¸�ɮ");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","�˹�����ʥɮ");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","�˹�������ɮ");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","�˹����»��");
                return ;
        } else
                student->set("title","�˹����¸�����");
                return ;

}

