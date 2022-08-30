export type Attachment = {
  name: string,
  url: string,
  size: number
}

export type Message = {
  author: string,
  avatar: string,
  content: string,
  timestamp: string,
  attachment?: Attachment,
  isCurrentUser?: boolean,
  isLecturer?: boolean,
}
