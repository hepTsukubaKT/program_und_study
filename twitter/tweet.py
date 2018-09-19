import twitter


api = twitter.Api(consumer_key="0lfJII4lfG9wEwuI8fjqCx0MG",
                  consumer_secret="8rrxEU6XeuXXor8maxOYXfdhxMzsMyfasBRJFTiIAV8SjPnMlK",
                  access_token_key="780446990-szO2uEsBVb5QOu3Ipf60rzIoGwaXE941TaFpeA0o",
                  access_token_secret="ygrpWifTtkThfP0WUsxRo1V72WV8sZSmEm6nFxCLqg5vg"
                  )
def tweet(testchr):
    api.PostUpdate(testchr)