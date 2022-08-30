import Footer from "../generic/Footer"
import { CustomHead } from "../generic/CustomHead"
import Header from "../generic/Header"

type Props = {
  title?: string,
  children: React.ReactNode,
  socketStatus: string
}

const BaseLayout = ({
  title,
  children,
  socketStatus
}: Props) => {
  return (
    <div className="min-h-screen transition-colors text-gray-900 bg-gray-100">
      <CustomHead title={title} />
      <Header socketStatus={socketStatus} />
        { children }
      <Footer />
    </div>
  ) 
}

export default BaseLayout