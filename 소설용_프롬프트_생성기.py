# -*- coding: utf-8 -*-
"""
Created on Thu Mar 23 10:31:28 2023

@author: user
"""
'''
# subject: 머신러닝; topic: 알고리즘; tc: 토픽 갯수; 
# wpp: 문단 단어수(words per paragraph)
def pg(subject,topic, tc, wpp):
    fp1=['나는 '+ subject +'에 대한 글을 작성할 거야. 다음의 절차를 준수해 줘.']
    fp2=['1.' +' '+ subject +'의 주요 '+topic+' '+str(tc)+'개를 나열해줘.']
    rp=[str(i+1)+'.'+ ' '+ '목록의 '+str(i)+'번째 요소에 대해 '\
        + str(wpp)+'글자로 작성해줘.' for i in range(1,tc+1)]
    tot=fp1+fp2+rp
    return '\n'.join(tot)    

print(pg('머신러닝','알고리즘',20,50))


# subject: 장르; topic: 목차; tc: 요소 갯수; 
# wpp: 문단 단어수(words per paragraph)
def pg1(subject,topic, tc, wpp):
    fp1=['나는 '+ subject +'을 작성할 거야. 다음의 절차를 준수해 줘.']
    fp2=['1.' +' '+ subject +'의 '+topic+' 요소 '+str(tc)+'개를 나열해줘.']
    rp=[str(i+1)+'.'+ ' '+ topic+'의 '+str(i)+'번째 요소에 대해 '\
        + str(wpp)+'단어로 구체적인 소설을 작성해줘.' for i in range(1,tc+1)]
    tot=fp1+fp2+rp
    return '\n'.join(tot)   

print(pg1('역사소설','목차',5,200))


# subject: 장르; topic: 목차; tc: 요소 갯수; 
# wpp: 문단 단어수(words per paragraph)
def pg2(subject,topic, tc, wpp):
    fp1=['나는 '+ subject +'을 작성할 거야. 다음의 절차를 준수해 줘.']
    fp2=['1.' +' '+ subject +'의 '+topic+' 요소 '+str(tc)+'개를 나열해줘.']
    rp=[str(i+1)+'.'+ ' '+ topic+'의 '+str(i)+'번째 요소에 대해 '\
        + str(wpp)+'단어로 구체적인 논문을 작성해줘.' for i in range(1,tc+1)]
    tot=fp1+fp2+rp
    return '\n'.join(tot)   

print(pg2('공학논문','목차',5,400))
'''


# subject: 머신러닝; topic: 알고리즘; tc: 토픽 갯수; 
# wpp: 문단 단어수(words per paragraph)
def pg3(subject,topic, tc):
    fp1=['나는 '+ subject +'에 대한 글을 작성할 거야. 다음의 절차를 준수해 줘.']
    fp2=['1.' +' '+ subject +'의 주요 '+topic+' '+str(tc)+'개를 나열해줘.']
    rp=[str(i+1)+'.'+ ' '+ '목록의 '+str(i)+'번째 요소를 이해하기 쉬운 '\
        + '파이썬 코드를 작성해줘.' for i in range(1,tc+1)]
    tot=fp1+fp2+rp
    return '\n'.join(tot)    

print(pg3('머신러닝','알고리즘',3))

