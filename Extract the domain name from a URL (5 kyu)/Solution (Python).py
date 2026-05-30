import re

def domain_name(url):
    return re.search('(?:https?://)?(?:www\.)?([^/.]+)', url).group(1)