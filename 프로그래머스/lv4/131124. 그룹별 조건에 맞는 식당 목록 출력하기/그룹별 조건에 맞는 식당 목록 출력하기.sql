-- 코드를 입력하세요
SELECT a.MEMBER_NAME, b.REVIEW_TEXT, date_format(b.REVIEW_DATE, '%Y-%m-%d')
from MEMBER_PROFILE a join REST_REVIEW b on a.MEMBER_ID=b.MEMBER_ID
where b.MEMBER_ID = 
(select member_id from rest_review group by member_id order by count(review_id) desc limit 1)
order by REVIEW_DATE, REVIEW_TEXT