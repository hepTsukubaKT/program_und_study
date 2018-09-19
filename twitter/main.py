import tweet
from datetime import datetime


tweetstr=datetime.now().strftime("%Y/%m/%d %H:%M:%S")+" "+input()
tweet.tweet(tweetstr)