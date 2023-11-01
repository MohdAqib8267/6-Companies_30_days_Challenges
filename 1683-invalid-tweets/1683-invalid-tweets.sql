# Write your MySQL query statement below
select tw.tweet_id as tweet_id from Tweets as tw
where LENGTH(tw.content) > 15