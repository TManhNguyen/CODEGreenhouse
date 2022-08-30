import { DOMAttributes, ReactNode } from "react"

type Props = {
  title: string,
  children: React.ReactNode,
  isOn?: boolean
}

const GenericToggle = ({
  title,
  children,
  isOn,
  ...props
}: Props & DOMAttributes<React.ReactNode>) => {
  return (  
    <div onClick={props.onClick} className={`w-full p-4 cursor-pointer rounded-xl transition-colors ${isOn ? "bg-blue-500 text-white hover:bg-blue-600" : "bg-gray-200 text-black hover:bg-gray-300"}`}>
      { children }
      <span className="text-xl font-medium truncate">{title}</span>
    </div>
  ) 
}

export default GenericToggle