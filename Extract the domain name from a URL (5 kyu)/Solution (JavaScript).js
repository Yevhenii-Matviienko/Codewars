function domainName(url) {
  return url
    .replace(/https?:\/\//, '')
    .replace(/www\./, '')
    .split('.')[0];
}