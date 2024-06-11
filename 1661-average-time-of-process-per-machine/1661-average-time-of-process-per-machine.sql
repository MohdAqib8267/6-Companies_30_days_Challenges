# Write your MySQL query statement below
select a1.machine_id,round(avg(a1.timestamp-a2.timestamp),3) as processing_time from Activity as a1, Activity as a2
where a1.machine_id = a2.machine_id And a1.process_id = a2.process_id And a1.activity_type='end' And a2.activity_type='start'
group by machine_id