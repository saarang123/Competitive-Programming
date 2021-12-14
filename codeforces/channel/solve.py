s = """g fmnc wms bgblr rpylqjyrc gr zw fylb. rfyrq ufyr amknsrcpq ypc dmp. bmgle gr gl zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle. sqgle qrpgle.kyicrpylq() gq pcamkkclbcb. lmu ynnjw ml rfc spj."""

ans = ""
for c in s:
    if c.isalpha():
        ans += chr(ord('a') + (ord(c) - ord('a') + 2) % 26)
    else:
        ans += c
print(ans)
