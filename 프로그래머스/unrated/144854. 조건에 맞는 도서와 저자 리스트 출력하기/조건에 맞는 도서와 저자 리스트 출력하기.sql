-- 코드를 입력하세요
SELECT a.BOOK_ID, b.AUTHOR_NAME, date_format(a.PUBLISHED_DATE, '%Y-%m-%d')
from BOOK a join AUTHOR b on  a.AUTHOR_ID=b.AUTHOR_ID
where a.CATEGORY='경제'
order by PUBLISHED_DATE asc