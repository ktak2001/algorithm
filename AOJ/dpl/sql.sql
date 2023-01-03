drop procedure if exists test;
delimiter //
create procedure test()
begin
	declare userId int default 1;
	declare tmp int;
	declare tname varchar(20);
	declare created date;
	declare tid int default 0;
	declare addedR int default 0;
	declare N int;
	drop table if exists newRewards;
	create table newRewards (user_id int, name varchar(20), reward int);
	select count(*) from reward into N;
	loop1: loop
		set tid = tid + 1;
		if tid > N then
			leave loop1;
		end if;
		select reward.user_id, reward.reward, reward.created from reward where id = tid into userId, tmp, created;
		if created < '2019-01-01' then
			iterate loop1;
		end if;
		select count(*) from newRewards where user_id = userId into @chk;
		if @chk > 0 then
			update newRewards set reward = reward + tmp where user_id=userId;
		else
			select name from users where id = userId into tname;
			insert into newRewards values (userId, tname, tmp);
		end if;
	end loop loop1;
	select * from newRewards order by reward desc;
end
//
delimiter ;
call test();


